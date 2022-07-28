#include"angle_func.h"
vector<double> vecdiff(vector<double> &a, vector<double> &b)
{
    vector<double> c(a.size());
    if (a.size() != b.size())
    {
        cout << "Error! vecdiff size unmatched" << endl;
        return c;
    }
    for (int i = 0; i < a.size(); i++)
    {
        c[i] = a[i] - b[i];
    }
    return c;
}

vector<double> normalvec(vector<double> &a, vector<double> &b)
{
    vector<double> nvec;
    if (a.size() != 3 || b.size() != 3)
    {
        cout << "Error, inputs are not validate vectors." << endl;
        return nvec;
    }
    nvec = {
        a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
    double ra2 = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    double rb2 = b[0] * b[0] + b[1] * b[1] + b[2] * b[2];
    if (ra2 == 0 || rb2 == 0)
    {
        cout << "Error, vector length is zero!||from fun cosvec" << endl;
        return nvec;
    }
    for (int i = 0; i < nvec.size(); i++)
        nvec[i] /= sqrt(ra2 * rb2);
    return nvec;
}
double cosvec(vector<double> &a, vector<double> &b)
{
    if (a.size() != 3 || b.size() != 3)
    {
        cout << "Error, inputs are not validate vectors." << endl;
        return -100;
    }
    double ra2 = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    double rb2 = b[0] * b[0] + b[1] * b[1] + b[2] * b[2];
    if (ra2 == 0 || rb2 == 0)
    {
        cout << "Error, vector length is zero!||from fun cosvec" << endl;
        return -100;
    }
    return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]) / sqrt(ra2 * rb2);
}
