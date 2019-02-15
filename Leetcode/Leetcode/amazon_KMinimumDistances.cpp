/*
K Minimum Distances	-	Amazon OA2

You are in charge of preparing a recently purchased lot for one of Amazon's new building. 
The lot is covered with trenches and has a single obstacle that needs to be taken down before the foundation can be prepared for the building. 
The demolition robot must remove the obstacle before process can be made on the building.

Write an algorithm to determine the minimum distance required for the demolition robot to remove the obstacle.

Assumptions:
The lot is flat, except for trenches, and can be represented as a two-dimensional grid.
The demolition robot must start from the top-left corner of the lot, which is always flat, and can move one block up, down, left, or right at a time.
The demolition robot cannot enter trenches and cannot leave the lot.
The flat areas are represented as 1, areas with trenches are represented by 0 and the obstacle is represented by 9.

Input
The input to the function/method consists of three arguments:
numRows, an integer representing the number of rows;
numColumns, an integer representing the number of columns;
lot, representing the two-dimensional grid of integers.

Output
Return an integer representing the minimum distance traversed to remove the obstacle else return -1.

Constraints
1 <= numRows, numColumns <= 100

Example
Input:
numROws = 3
numColumns = 3
lot = [[1, 0, 0],
	   [1, 0, 0],
	   [1, 9, 1]]

Output:
3

Explanation:
Starting from the top-left corner, the demolition robot traversed the cells (0,0) -> (1,0) ->(2,0) ->(2,1). The robot traversed the total distance 3 to remove the obstacle. So, the output is 3.

Testcase 2:
Input:
5, 4,
[[1, 1, 1, 1],
 [0, 1, 1, 1],
 [0, 1, 0, 1],
 [1, 1, 9, 1],
 [0, 0, 1, 1]]

 Expected Return Value:
 5
*/

int removeObstacle(int numRows, int numColumns, int **lot) {

}