void reverse(string& s, int st, int e)
{
    if (st > e)
    {
        return;
    }

    swap(s[st], s[e]);
    st++;
    e--;
    return reverse(s, st, e);
}