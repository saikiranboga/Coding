public class Solution {
  public static void main(String[] args) {
    Solution s = new Solution(2);
    s.RowAdd(0, 1);
    System.out.println(s.outputRow(0)); // 2
    System.out.println(s.outputCol(1)); // 1
    s.ColAdd(0, 2);
  }

  private final boolean[] columns;
  private final boolean[] rows;

  public Solution(int n) {
    columns = new boolean[n];
    rows = new boolean[n];
  }

  private void setRow(int i, boolean value) {
    rows[i] = value;
  }

  private void setCol(int i, boolean value) {
    columns[i] = value;
    columnUpdateTime[i] = ++time;
  }

  public boolean isSet(int romIndex, int columnIndex) {
    return rowUpdateTime[romIndex] > columnUpdateTime[columnIndex] ? rows[romIndex] : columns[columnIndex];
  }

  private int outputRow(int rowIndex) {
    int res = 0;
    for (int columnIndex = 0; columnIndex < columns.length; ++columnIndex) {
        if (isSet(rowIndex, columnIndex)) {
            ++res;
        }
    }
    return res;
  }

  private int outputCol(int columnIndex) {
    int res = 0;
    for (int rowIndex = 0; rowIndex < rows.length; ++rowIndex) {
        if (isSet(rowIndex, columnIndex)) {
            ++res;
        }
    }
    return res;
  }
}