class Node:
    def __init__(self, matrix, g_x, goal):
        self.matrix = matrix
        self.g_x = g_x
        self.f_x = 0
        self.h_x = 0
        self.goal = goal
        self.n = 3
        self.calculate_h_x()
        self.calculate_f_x()
    
    def locateZero(self):
        for i, row in enumerate(self.matrix):
            for j, ele in enumerate(row):
                if ele == 0:
                    return i, j

    def generateChild(self):
        x, y = self.locateZero()
        possible = [[x, y - 1], [x, y + 1], [x - 1, y], [x + 1, y]]
        children = []
        for i, j in possible:
            if 0 <= i < self.n and 0 <= j < self.n:
                child = [row[:] for row in self.matrix]
                child[x][y], child[i][j] = child[i][j], child[x][y]
                children.append(Node(child, self.g_x + 1, self.goal))
        return children
    
    def calculate_h_x(self):
        for i in range(self.n):
            for j in range(self.n):
                if self.matrix[i][j] != self.goal[i][j] and self.matrix[i][j] != 0:
                    self.h_x += 1

    def calculate_f_x(self):
        self.f_x = self.h_x + self.g_x

    def printNode(self):
        print()
        print(f"h(x): {self.h_x}")
        print(f"g(x): {self.g_x}")
        print(f"f(x): {self.f_x}")
        for row in self.matrix:
            print(*row)
        print()

class Puzzle:
    def __init__(self):
        self.visited = []
        self.expanded = []
        self.n = 3
        self.initial = [[] for _ in range(self.n)]
        self.goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
    
    def input(self, variable):
        for i in range(self.n):
            variable[i] = [int(j) for j in input().split(" ")]

    def solve(self):
        matrices = []
        print("Enter Initial State")
        self.input(self.initial)
        #if not self.is_solvable(self.initial):
        #    print("The initial state is unsolvable.")
        #    return

        current = Node(self.initial, 0, self.goal)
        matrices.append(current.matrix)
        self.expanded.append(current)

        while True:
            current = self.expanded.pop(0)
            if current.h_x == 0:
                break
            current.printNode()
            for child in current.generateChild():
                if child.matrix not in matrices:
                    matrices.append(child.matrix)
                    self.expanded.append(child)
            self.visited.append(current)
            self.expanded.sort(key=lambda x: x.f_x, reverse=False)
        current.printNode()
puzzle = Puzzle()
puzzle.solve()
