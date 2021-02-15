class Line:
    def __init__(self, x1, y1, x2, y2):  # use _x2 -> __init__
        self.start = [x1, y1]
        self.end = [x2, y2]
        self.slope = None
        self.intercept = None

    def findSlope(self):
        self.slope = (self.end[1]-self.start[1]) / \
            (self.end[0]-self.start[0])  # y2-y1/x2-x1

    def findIntercept(self):
        self.intercept = self.start[1] - \
            (self.slope*self.start[0])  # y1-slope*x1


def findIntersection(line1, line2):
    return (line2.intercept-line1.intercept)/(line1.slope-line2.slope)


# initializing lines
line1 = Line(1, 4, 3, 2)  # x1y1 x2y2
line1.findSlope()
line1.findIntercept()

line2 = Line(2, 0, 7, 4)
line2.findSlope()
line2.findIntercept()

if(line1.slope == line2.slope and line1.intercept == line2.intercept):
    print("Lines are equal f(x)=g(x)")
elif(line1.slope == line2.slope):
    print("lines are parallel")
else:
    intersection = findIntersection(line1, line2)
    if(min(line1.end[0], line2.end[0]) >= intersection and intersection >= max(line1.start[0], line2.start[0])):
        print("Two segments meet at:", intersection)
    else:
        print("Segments do not meet")
