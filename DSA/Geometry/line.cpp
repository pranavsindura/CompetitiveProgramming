struct line
{
    double a, b, c;

    line() {}
    line(point p, point q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        double z = sqrt(a * a + b * b);
        if (abs(z) > eps)
            a /= z, b /= z, c /= z;
    }

    double dist(point p) const
    {
        return a * p.x + b * p.y + c;
    }
};



/*====================================LINE SEGMENT==============================================*/


// CHECK INTERSECTION
// Convert for double if required

bool intersect_1D(int a, int b, int c, int d)
{
    if(a > b)
        swap(a, b);
    if(c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}
int sg(int x)
{
    if(x > 0)
        return 1;
    else if(x < 0)
        return -1;
    else
        return 0;
}

bool intersect(pair<point, point> &l1, pair<point, point> &l2)
{
    point a = l1.ff, b = l1.ss;
    point c = l2.ff, d = l2.ss;

    if(c.cross(d, a) == 0 && c.cross(d, b) == 0)
    {
        //lie on same line
        // Check if when projected on X axis intersect
        // and when projected on Y axis intersect
        if(intersect_1D(a.x, b.x, c.x, d.x) && intersect_1D(a.y, b.y, c.y, d.y))
            return true;
        else
            return false;
    }
    // Both points of one segment must lie on either side of the other segment
    // Signs of cross product must be opposite
    // CCW Test
    if(sg(c.cross(d, a)) != sg(c.cross(d, b)) && sg(a.cross(b, c)) != sg(a.cross(b, d)))
        return true;
    else
        return false;
}

// A bit simplified

bool intersect(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3 == p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}


// FIND INTERSECTION
/*
    ============================INTERSECTION OF SEGMENTS===============================

    ================================Cartesian Form=====================================

    Segments AB and CD


    Many Cases, best way is

    If Lines DO NOT Intersect in 1D both X and Y:
        THEY DONT INTERSECT
    Else:
        Find Delta using Cramer's Rule (Refer Line intersection)

        If Delta < eps:
            Lines are either parallel or identical
            If distance of C from AB is > eps or distance of A from CD is > eps:
                Lines don't overlap
                Lines are parallel or they are similar and still far apart
                A----------B        or      A---------B   C-------------D

                C----------D
                THEY DONT INTERSECT
            Else:
                Lines Overlap

                Find the overlapping segment
                Max(A,C) - Min(B, D)

                THEY INTERSECT
        Else:
            Find Intersection coordinates as you would with Cramer's Rule
            Now it is still possible that line segments do not intersect

            Check is the intersection point lies between the respective 1D coordinates or the Segments
            A.x <= P.x + eps <= B.x, A.y <= P.y + eps <= B.y
            C.x <= P.x + eps <= D.x, C.y <= P.y + eps <= D.y

            If conditions are met:
                THEY INTERSECT
            Else:
                THEY DONT INTERSECT
*/

bool intersect_segments(point a, point b, point c, point d, point &intersect)
{
    point origin(0, 0);
    double d1 = origin.cross(a - b, d - c), d2 = origin.cross(a - c, d - c), d3 = origin.cross(a - b, a - c);
    if(fabs(d1) < eps) return false; // Parallel || identical
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    if(t2 < -eps || t2 > 1 + eps)
        return false;
    return true;
}


// CHECK IF POINT LIES ON SEGMENT
// Is point P on segment AB
// For doubles
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}
// Simplified for integers
bool is_point_on_segment(point A, point B, point P)
{
    return (A.cross(P, B) == 0 &&
            dp(P - A, B - A) <= dp(A - B, A - B) &&
            dp(P - B, A - B) <= dp(A - B, A - B));
}

// Combine together to get
bool get_intersection(point a, point b, point c, point d, point &intersect)
{
    return intersect_segments(a, b, c, d, intersect) && 
    is_point_on_segment(a, b, intersect) && 
    is_point_on_segment(c, d, intersect);
}




// Find a point on the segment AB that is D distance away from A
// D must be < length(A, B) for point to be on the segment
// otherwise it will give point on line AB, need to combine with is_point_on_segment
point get_point_on_line(point A, point B, double D)
{
    double ratio = D / length(A, B);
    return point(A.x + ratio * (B.x - A.x), A.y + ratio * (B.y - A.y));
}




/*=================================LINE=======================================*/


/*
    ======================LINE INTERSECTION=====================

    ======================Parametric form=======================
    Line 1 -
        r = a1 + t * d1
    Line 2 -
        r = a2 + t2 * d2

    r x d2 = 0

    Substitute r and solve for t

    t = ((a2 - a1) x d2) / (d1 x d2)

    Plug t in Line 1 and find Intersection point

    If lines are parallel -> d1 x d2 = 0, No solution
    If lines are Identical -> ((a2 - a1) x d2) = 0 and above condition, Infinitely Many solutions


    ====================Cartesian Form===========================

    Line 1 -
        a1x + b1y + c1 = 0
    Line 2 -
        a2x + b2y + c2 = 0

    Solve System of Linear Equations
    Can use Cramers Rule

    Delta =     |a1 b1|
                |a2 b2|

    Delta_x =   |c1 b1|
                |c2 b2|

    Delta_y =   |a1 c1|
                |a2 c2|

    x = -Delta_x/Delta
    y = -Delta_y/Delta

    If Lines are parallel -> Delta = 0, NO solution

    If lines are identical -> Delta_x = 0, Delta_y = 0, Delta = 0, Infinitely Many Solutions
*/

// Parametric
point intersect(point a1, point d1, point a2, point d2)
{
    point t = a2 - a1;
    return a1 + t.cross(d2) / d1.cross(d2) * d1;
    // return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}

// Cartesian
const double eps = 1e-9;

double det(double a, double b, double c, double d)
{
    return a * d - b * c;
}

bool intersect(line m, line n, point &res)
{
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < eps)
        return false;
    res.x = -det(m.c, m.b, n.c, n.b) / zn;
    res.y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool parallel(line m, line n)
{
    return abs(det(m.a, m.b, n.a, n.b)) < eps;
}

bool equivalent(line m, line n)
{
    return abs(det(m.a, m.b, n.a, n.b)) < eps
           && abs(det(m.a, m.c, n.a, n.c)) < eps
           && abs(det(m.b, m.c, n.b, n.c)) < eps;
}