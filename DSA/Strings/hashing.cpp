array<ll, MAXN> P, invP;
const ll HMOD = 1e9 + 9;
void init_hash()
{
    P[0] = 1;
    for(int i = 1; i < MAXN; i++)
        P[i] = (P[i - 1] * 31) % HMOD;
    ll x = fpow(31, HMOD - 2, HMOD); // make constant after finding what the val is
    invP[0] = 1;
    for(int i = 1; i < MAXN; i++)
        invP[i] = (invP[i - 1] * x) % HMOD;
}

pair<vector<ll>, vector<ll>> build_hash(string &s)
{
    int n = ln(s);
    vector<ll> pref(n), suff(n);
    for(int i = 0; i < n; i++)
    {
        pref[i] = ((s[i] - '0' + 1) * P[i]) % HMOD;
        if(i) pref[i] = (pref[i] + pref[i - 1]) % HMOD;
    }
    for(int i = n - 1; i >= 0; i--)
    {
        suff[i] = ((s[i] - '0' + 1) * P[n - i - 1]) % HMOD;
        if(i + 1 < n) suff[i] = (suff[i] + suff[i + 1]) % HMOD;
    }
    return {pref, suff};
}
ll get_pref(int L, int R, vector<ll> &pref)
{
    ll v = pref[R] - (L ? pref[L - 1] : 0);
    v = (v + HMOD) % HMOD;
    v = (v * invP[L]) % HMOD;
    return v;
}
ll get_suff(int L, int R, vector<ll> &suff)
{
    ll v = suff[L] - (R + 1 < sz(suff) ? suff[R + 1] : 0);
    v = (v + HMOD) % HMOD;
    v = (v * invP[sz(suff) - R - 1]) % HMOD;
    return v;
}