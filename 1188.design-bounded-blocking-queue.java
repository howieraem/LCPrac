/*
 * @lc app=leetcode id=1188 lang=java
 *
 * [1188] Design Bounded Blocking Queue
 */
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

// @lc code=start
class BoundedBlockingQueue {
    private int[] q;
    private int size = 0, tail = 0, head = 0;
    private ReentrantLock lock = new ReentrantLock();
    private Condition full = lock.newCondition(), empty = lock.newCondition();

    public BoundedBlockingQueue(int capacity) {
        q = new int[capacity];
    }
    
    public void enqueue(int element) throws InterruptedException {
        lock.lock();
        try {
            while (size == q.length) {
                full.await();
            }
            q[tail++] = element;
            tail %= q.length;
            ++size;
            empty.signal();
        } finally {
            lock.unlock();
        }
    }

    public int dequeue() throws InterruptedException {
        lock.lock();
        try {
            while (size == 0) {
                empty.await();
            }
            int front = q[head++];
            head %= q.length;
            --size;
            full.signal();
            return front;
        } finally {
            lock.unlock();
        }
    }
    
    public int size() throws InterruptedException {
        lock.lock();
		try {
			return this.size;
		} finally {
			lock.unlock();
		}
    }
}
// @lc code=end

