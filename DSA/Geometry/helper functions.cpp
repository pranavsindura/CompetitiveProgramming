int dcmp(double a, double b)
{
    return  (fabs(a - b) < eps) ? 0 : (a < b ? -1 : +1);
}

bool same(point a, point b)
{
    return (dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0);
}

// Needed for acos
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

// Rotate vector P by a radians cw
point rotate(point p, double a)
{
    return point(p.x * cos(a) + p.y * sin(a), p.y * cos(a) - p.x * sin(a));
}

// rotate point P by ang radians around point T
point rotate(point p, double ang, point t)
{
    point Q;
    Q.x = t.x + (p.x - t.x) * cos(ang) - (p.y - t.y) * sin(ang);
    Q.y = t.y + (p.x - t.x) * sin(ang) + (p.y - t.y) * cos(ang);
    return Q;
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

// CCW Test

// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
// Need length
int ccw(point a, point b, point c)
{
    point v1(b - a), v2(c - a);
    double t = v1.cross(v2);

    if (t > +eps)
        return +1;
    if (t < -eps)
        return -1;
    if (v1.x * v2.x < -eps || v1.y * v2.y < -eps)
        return -1;
    if (length(v1, point(0, 0)) < length(v2, point(0, 0)) - eps)
        return +1;
    return 0;
}