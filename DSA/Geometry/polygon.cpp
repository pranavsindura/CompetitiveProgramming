/*
    POLYGON NOTES
    INPUT
        - Coordinates real/integer
        - Ordered? CCW? CW?
        - Duplicate points?
        - Collinear points?
        - n < 3? INVALID, n = 3 is special case
    TYPE
        - Simple / Non Simple
        - Convex / Concave

    MODULO IS EXPENSIVE FOR LARGE CONSTRAINTS
    > 10^6
    Consider repeating the first point, cheaper
*/

// SIMPLE POLYGON
// NO edges should intersect, except adjacent
// O(N^2)

bool is_simple(vector<point> &p)
{
    int n = sz(p);
    p.push_back(p[0]);
    bool ok = true;
    for(int i = 0; i < n && ok; i++)
        for(int j = i + 1; j < n && ok; j++)
            if(intersect(p[i], p[i + 1], p[j], p[j + 1]) && (i != 0 || j != n - 1))
                ok = false;
    p.pop_back();
    return ok;
}

// CONVEX POLYGON
// Assuming that the points are ordered CW or CCW
// The angles between adjacent edges must be <= 180
// We can use CCW test to see if all 3 consecutive vertices follow same Cross Product sign

bool is_convex(vector<point> &p)
{
    int n = sz(p);
    p.push_back(p[0]), p.push_back(p[1]);
    int sign = ccw(p[0], p[1], p[2]);
    bool ok = true;
    for(int i = 0; i < n && ok; i++)
        if(ccw(p[i], p[i + 1], p[i + 2]) != sign)
            ok = false;
    p.pop_back(), p.pop_back();
    return ok;
}

// CONCAVE POLYGON
// is_concave = !is_convex

// POLYGON AREA
// Points should be ordered CW/CCW
// Works for tricky inputs, duplicate points, collinear points
// Final summation > 0 -> CCW, < 0 -> CW
double polygon_area(vector<point> &p)
{
    if(sz(p) < 3) return 0;
    point origin(0, 0);
    int n = sz(p);
    p.push_back(p[0]);
    double area = 0;
    for(int i = 0; i < n; i++)
        area += origin.cross(p[i], p[i + 1]);
    p.pop_back();
    return fabs(area / 2.0);
}


// PICK'S THEOREM
// For simple polygon with integer coordinates
// Area = Internal_points + Boundary_points / 2 - 1
// Boundary points of vector(x,y) = gcd(x,y)
// UVA 10088, UVA 137



// POLYGON CENTROID
// We use polygon decomposition to find the centroid
// We break the polygon into triangles containing origin and 2 vertices of a side
// Cx = sum(Cx_i * A_i) / sum(A_i)
// after some maths
// Cx = 1/6A * sum((x_i * x_i+1) * (x_i * y_i+1 - x_i+1 * y_i))
// Cy = 1/6A * sum((y_i * y_i+1) * (x_i * y_i+1 - x_i+1 * y_i))

point polygon_centroid(vector<point> &p)
{
    point origin(0, 0);
    double x = 0, y = 0, a = 0, c;
    int n = sz(p);
    p.push_back(p[0]);
    for(int i = 0; i < n; i++)
    {
        c = origin.cross(p[i], p[i + 1]), a += c;
        x += (p[i].x + p[i + 1].x) * c;
        y += (p[i].y + p[i + 1].y) * c;
    }
    p.pop_back();

    if(dcmp(a, 0) == 0) // Line
        return (p.front() + p.back()) * 0.5;
    a /= 2, x /= 6 * a, y /= 6 * a;

    // Fix Values
    if(dcmp(x, 0) == 0) x = 0;
    if(dcmp(y, 0) == 0) y = 0;

    return point(x, y);
}

// POLYGON CUT
// We can see which set each point belongs to, based on the CCW test
// If the side intersects the vector AB then the intersection belongs to both sets
// assumes points in P are in order
// UVA 588, UVA 11460, UVA 137
//             B
//            /|\
//             |
//      .      |       .
//    left     |     right
//             |
//             |
//             A

pair<vector<point>, vector<point>> polygon_cut(vector<point> &p, point A, point B)
{
    vector<point> left, right;
    point inter;
    point seg = B - A;
    for(int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        point v = cur - A;

        if(seg.cross(v) >= 0)
            left.pb(cur);

        if(seg.cross(v) <= 0)
            right.pb(cur);
        //NOTE intersect_segments should handle AB as line
        if(intersect_segments(A, B, cur, nxt, inter))
            right.pb(inter), left.pb(inter);

    }
    return mp(left, right);
}

// Point inside Polygon
// Check using Winding Number Algorithm
// O(n)
// There exists O(logn) for convex polygons, precomputation is involved, Preparata Algorithm
// Is point P on segment AB
// UVA 881
bool is_point_on_segment(point A, point B, point P)
{
    double AB = length(A, B), AP = length(A, P), BP = length(B, P);
    return dcmp(AB - AP - BP, 0) == 0;
}

bool is_inside_polygon(vector<point> &p, point p0)
{
    int wn = 0;
    for(int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        if(is_point_on_segment(cur, nxt, p0))
            return true;
        if(cur.y <= p0.y) // Edge going up
        {
            if(nxt.y > p0.y && (nxt - cur).cross(p0 - cur) > eps)
                wn++;
        }
        else // Edge going Down
        {
            if(nxt.y <= p0.y && (nxt - cur).cross(p0 - cur) < -eps)
                wn--;
        }
    }
    return wn != 0;
}

// POLYGON POLYGON INTERSECTION
// Check if one vertex inside other
// Check if edges intersect
// O(n^2)
bool polygon_intersection(vector<point> &a, vector<point> &b)
{
    int n = sz(a), m = sz(b);
    a.pb(a.front()), b.pb(b.front());
    bool inter = false;
    for(int i = 0; i < n && !inter; i++)
        inter |= is_inside_polygon(b, a[i]);
    for(int i = 0; i < m && !inter; i++)
        inter |= is_inside_polygon(a, b[i]);
    for(int i = 0; i < n && !inter; i++)
        for(int j = 0; j < m && !inter; j++)
            inter |= intersect_segments(a[i], a[(i + 1)], b[j], b[(j + 1)]);
    a.pop_back(), b.pop_back();
    return inter;
}

double polygon_shortest_distance(vector<point> &a, vector<point> &b)
{
    int n = sz(a), m = sz(b);
    if(polygon_intersection(a, b)) return 0;
    a.pb(a.front()), b.pb(b.front());

    double ans = DBL_MAX;
    point C;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // point a[i] with point b[j]
            C = a[i];
            ans = min(ans, length(a[i], b[j]));
            // point a[i] with edge b[j] ---- b[j + 1]
            point A = b[j], B = b[j + 1];
            point AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            point D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
            // point b[j] with edge a[i] ---- a[i + 1]
            C = b[j];
            A = a[i], B = a[(i + 1)];
            AD = (B - A) * dp(B - A, C - A) / dp(B - A, B - A);
            D = AD + A;
            if(is_point_on_segment(A, B, D))
                ans = min(ans, length(C, D));
        }
    }
    a.pop_back(), b.pop_back();
    return ans;
}

// CONVEX HULL
// UVA 10002
vector<point> convex_hull(vector<point> &points)
{
    sort(begin(points), end(points));
    vector<point> hull;
    hull.reserve(points.size() + 1);
    for (int phase = 0; phase < 2; ++phase)
    {
        auto start = hull.size();
        for (auto &p : points)
        {
            while (hull.size() >= start + 2 &&
                    p.cross(hull.back(), hull[hull.size() - 2]) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(begin(points), end(points));
    }
    if (hull.size() == 2 && hull[0] == hull[1]) hull.pop_back();
    return hull;
}
