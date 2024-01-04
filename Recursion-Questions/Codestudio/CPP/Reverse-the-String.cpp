/*
Question link:- https://www.codingninjas.com/studio/problems/reverse-the-string_799927
*/

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

string reverseString(string str)
{
	reverse(str, 0, str.length()-1);
	return str;
}