/*
    ===============================CIRCLES==============================

    Circle can be found by 3 points on Circumference

    Perpendicular Bisectors of two chords meet at center
    Intersect Segments of perpendicular bisectors
*/

pair<double, point> find_circle(point a, point b, point c)
{
    point m1 = (a + b) * 0.5, v1 = b - a, pv1 = point(v1.y, -v1.x);
    point m2 = (c + b) * 0.5, v2 = b - c, pv2 = point(v2.y, -v2.x);

    point end1 = pv1 + m1, end2 = pv2 + m2;
    point center;

    intersect_segments(m1, end1, m2, end2, center);

    return {length(center, a), center};
}
/*
    ===============================Line and Circle Intersection============================
    0,1,2 points

    Line -> r = p0 + t * (p1 - p0), p0 and p1 are points on line
    Circle -> (p-c) . (p-c) = r^2, p is point on circle, c is center r is radius

    Since point also lies on line
    p = p0 + t * (p1 - p0)

    Substitute in equation of circle

    (p0 + t * (p1 - p0) - c) . (p0 + t * (p1 - p0) - c) = r^2
    (p0 + t * (p1 - p0) - c)^2 = r^2

    (p1- p0)^2 * t^2 + 2 * (p1-p0) * (p0 - c) * t + (p0 - c)^2 = r^2

    Solve ax^2 + bx + c = 0
*/
vector<point> intersectLineCircle(point p0, point p1, point C, double r)
{
    // dp -> dot product
    double a = dp(p1 - p0, p1 - p0), b = 2 * dp(p1 - p0, p0 - C),
           c = dp(p0 - C, p0 - C) - r * r;
    double f = b * b - 4 * a * c;

    vector<point> v;
    if( dcmp(f, 0) >= 0)
    {
        if( dcmp(f, 0) == 0)    f = 0;
        double t1 = (-b + sqrt(f)) / (2 * a);
        double t2 = (-b - sqrt(f)) / (2 * a);
        v.push_back( p0 + (p1 - p0) * t1 );
        if( dcmp(f, 0) != 0)    v.push_back( p0 + (p1 - p0) * t2 );
    }
    return v;
}

/*
    =========================Circle Circle Intersection==========================

    1. CHECK INTERSECTION

    Let d = distance between centers of C1 and C2
        If d <= R1+R2:
            intersection may occur
            Now we should check if smaller circle lies inside bigger circle or not

            If d + Rmin <= Rmax:
                smaller circle lies inside no intersection
                This also covers same circle as no intersection
            else:
                Intersection!

        else:
            no intersection, circles are far apart


    2. FIND INTERSECTION POINTS

    Lots of cases
    First check same circle

    Now form triangle b/w C1, C2 and Intersection point P1 and P2

    Find angle between P-C1-C2 using cosine law and between C2-C1-X-axis using dot product

    Find P1

    Check if it lies on circle, if not then they dont intersect

    Find P2
    check if p1 and p2 are same


*/

//==============================CHECK INTERSECTION===========================
struct point
{
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}
// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool check_intersection(point c1, double r1, point c2, double r2)
{
    // Intersection occurs when distance between centers in <= r1+r2
    // Also check that circle does not lie inside circle
    double d = length(c1, c2);
    if(dcmp(d, r1 + r2) <= 0)
    {
        double rmin = r1;
        double rmax = r2;
        if(dcmp(rmin, rmax) > 0)
            swap(rmin, rmax);
        // if d + rmin <= rmax, smaller circle lies inside, we dont want that
        if(dcmp(d + rmin, rmax) <= 0)
            return false;
        else
            return true;
    }
    return false;
}


//==============================FIND INTERSECTION POINTS===========================

int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

bool same(point a, point b)
{
    return (dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0);
}

double fix_angle(double val)
{
    // fix value between -1 and 1
    return ((val > 1) ? 1 : (val < -1) ? -1 : val);
}

double get_angle_C_ABC(double a, double b, double c)
{
    // c^2 = a^2 + b^2 - 2*a*b*cos(C)
    double val = a * a + b * b - c * c;
    val /= (2.0 * a * b);
    val = fix_angle(val);
    double ang = acos(val);
    return ang;
}

// Dot product
double dp(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

// Euclidean Distance
double length(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double angle(point a)
{
    // Angle with X axis
    return atan2(a.y, a.x);
}

point polar(double r, double ang)
{
    return point(r * cos(ang), r * sin(ang));
}

vector<point> circle_intersection(point c1, double r1, point c2, double r2)
{
    // Check for same first
    if(same(c1, c2) && dcmp(r1, r2) == 0 && r1 > eps)
        return vector<point>(3, c1);

    // Get alpha and beta
    double alpha = get_angle_C_ABC(r1, length(c1, c2), r2);
    double beta = angle(c2 - c1);
    // fix NaN
    if(isnan(alpha))
        alpha = 0;
    point p1 = polar(r1, alpha + beta) + c1;

    vector<point> ans;
    // Check if p1 is on circle
    if(dcmp(dp(p1 - c1, p1 - c1), r1 * r1) != 0 || dcmp(dp(p1 - c2, p1 - c2), r2 * r2) != 0)
        return ans;
    ans.pb(p1);

    point p2 = polar(r1, - alpha + beta) + c1;
    ans.pb(p2);
    // Check if they are same
    if(same(ans[0], ans[1]))
        ans.pop_back();
    return ans;
}


/*
    Minimal Enclosing Circle

    Smallest circle that encloses given list of points
    O(N) recursive randomized algorithm by Emo Welzl

    Find MEC for n-1 points and see if nth point is also inside circle
    If yes:
        OK
    else:
        Include Find new circle with nth point on the circle
*/

// Refer SPOJ - Aliens, UVA 438, ABC151-F, UVA 10005

point r[3], cen;
double rad;
int ps, rs; // ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);       rs = 0;
void MEC(vector<point> &arr)
{
    if(ps == 0 && rs == 2)
    {
        cen = (r[0] + r[1]) * 0.5;
        rad = length(r[0], cen);
    }
    else if(rs == 3)
    {
        pair<double, point> p = find_circle(r[0], r[1], r[2]);
        cen = p.second;
        rad = p.first;
    }
    else if(ps == 0)
    {
        cen = r[0]; // sometime be garbage, but will not affect
        rad = 0;
    }
    else
    {
        ps--;
        MEC(arr);

        if(length(arr[ps], cen) > rad)
        {
            r[rs++] = arr[ps];
            MEC(arr);
            rs--;
        }

        ps++;
    }
}