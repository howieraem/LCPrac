#
# @lc app=leetcode id=489 lang=python3
#
# [489] Robot Room Cleaner
#

# @lc code=start
# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """

class Solution:
    D = (0, 1, 0, -1, 0)    # initial direction is up (0, 1)

    # The API of robot forces that if you want to visit a node, 
    # you have to move there. Thus, BFS is not quite suitable.
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        self.dfs(robot, (0, 0), 0, set())

    @staticmethod
    def dfs(robot, point, cur_dirn, vis):
        robot.clean()
        vis.add(point)
        for k in range(4):
            new_dirn = (cur_dirn + k) & 3  # % 4
            next_point = (point[0] + Solution.D[new_dirn], 
                          point[1] + Solution.D[new_dirn + 1])
            if next_point not in vis and robot.move():
                Solution.dfs(robot, next_point, new_dirn, vis)
                Solution.reset(robot)
            robot.turnRight()

    @staticmethod
    def reset(robot):
        # Because of the nature of robot.move(), if we want to 
        # visit another direction from the previous step, we 
        # need to go back and keep the current direction.

        # Turn 180 deg (reverse the direction)
        # (can also do turnRight() twice)
        robot.turnLeft()
        robot.turnLeft()

        # Move back one step
        robot.move()

        # Turn 180 deg again to recover the original direction
        # (can also do turnLeft() twice)
        robot.turnRight()
        robot.turnRight()

# @lc code=end

