from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    height = len(a) + 1
    width = len(b) + 1
    matrix = [[(0, None)] * width for i in range(height)]
    for i in range(height):
        matrix[i][0] = (i, Operation.DELETED)
    for j in range(width):
        matrix[0][j] = (j, Operation.INSERTED)
    matrix[0][0] = (0, None)

    #print(matrix)

    for i in range(1, height):
        for j in range (1, width):
            deleted = matrix[i - 1][j]
            inserted = matrix[i][j - 1]
            subbed = matrix[i - 1][j - 1]
            if a[i-1] == b[j-1]:
                minimum = min(deleted[0] + 1, inserted[0] + 1, subbed[0])
                if minimum == deleted[0] + 1:
                    matrix[i][j] = (deleted[0] + 1, Operation.DELETED)
                elif minimum == inserted[0] + 1:
                    matrix[i][j] = (inserted[0] + 1, Operation.INSERTED)
                elif minimum == subbed[0]:
                    matrix[i][j] = (subbed[0], Operation.SUBSTITUTED)
            else:
                minimum = min(deleted[0] + 1, inserted[0] + 1, subbed[0] + 1)
                if minimum == deleted[0] + 1:
                    matrix[i][j] = (deleted[0] + 1, Operation.DELETED)
                elif minimum == inserted[0] + 1:
                    matrix[i][j] = (inserted[0] + 1, Operation.INSERTED)
                elif minimum == subbed[0] + 1:
                    matrix[i][j] = (subbed[0] + 1, Operation.SUBSTITUTED)

    return matrix
    return [[]]
