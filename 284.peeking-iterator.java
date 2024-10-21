/*
 * @lc app=leetcode id=284 lang=java
 *
 * [284] Peeking Iterator
 */

// @lc code=start
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
import java.util.NoSuchElementException;

// T: O(1)
// S: O(1)
class PeekingIterator implements Iterator<Integer> {
	private Integer next;
	private Iterator<Integer> it;
	private boolean noElem;
	
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.it = iterator;
		if (this.it.hasNext()) {
			next = this.it.next();
			noElem = false;
		} else {
			noElem = true;
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (noElem) {
			throw new NoSuchElementException();
		}
		Integer ans = next;
		if (this.it.hasNext()) {
			next = this.it.next();
			noElem = false;
		} else {
			noElem = true;
		}
		return ans;
	}
	
	@Override
	public boolean hasNext() {
	    return !noElem;
	}
}
// @lc code=end

