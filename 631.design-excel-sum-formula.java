/*
 * @lc app=leetcode id=631 lang=java
 *
 * [631] Design Excel Sum Formula
 */
import java.util.*;

// @lc code=start
class Excel {
    class Cell {
        int v;
        final Map<Cell, Integer> otherCellCnts = new HashMap<>();

        Cell(int _v) { v = _v; };

        // If this cell is defined as the sum formula,
        // store the counts of the cells referenced.
        // T: O(1)
        void add(Cell c) {
            otherCellCnts.put(c, otherCellCnts.getOrDefault(c, 0) + 1);
        }

        // T: O(n)
        int val() {
            if (otherCellCnts.isEmpty()) return v;
            else {
                int sum = 0;
                for (Cell c : otherCellCnts.keySet()) {
                    sum += otherCellCnts.get(c) * c.val();
                }
                return sum;
            }
        }

        // A constant value is set to this cell. Clear the counts.
        // T: O(1)
        void set(int _v) {
            v = _v;
            otherCellCnts.clear();
        }
    }

    private final Cell[][] cells;  // S: O(h * w)

    // T: O(h * w)
    public Excel(int height, char width) {
        final int h = height + 1, w = width - 'A' + 1;
        cells = new Cell[h][w];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cells[i][j] = new Cell(0);
            }
        }
    }
    
    // T: O(1)
    public void set(int row, char column, int val) {
        cells[row][column - 'A'].set(val);
    }

    // T: O(n) if the cell is defined as a sum of other cells
    public int get(int row, char column) {
        return cells[row][column - 'A'].val();
    }
    
    // T: O(n), n := the number of cells to be summed
    public int sum(int row, char column, String[] numbers) {
        Cell c = cells[row][column - 'A'];
        c.set(0);
        for (String s : numbers) {
            int k = s.indexOf(':');
            if (k > 0) {  // range of cells
                int[] start = getPos(s.substring(0, k)),
                      end = getPos(s.substring(k + 1));
                for (int i = start[0]; i <= end[0]; ++i) {
                    for (int j = start[1]; j <= end[1]; ++j) {
                        c.add(cells[i][j]);
                    }
                }
            } else {  // single cell
                int[] pos = getPos(s);
                c.add(cells[pos[0]][pos[1]]);
            }
        }
        return c.val();
    }

    private static int[] getPos(String s) {
        return new int[] {Integer.parseInt(s.substring(1)), s.charAt(0) - 'A'};
    }
}

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(height, width);
 * obj.set(row,column,val);
 * int param_2 = obj.get(row,column);
 * int param_3 = obj.sum(row,column,numbers);
 */
// @lc code=end

