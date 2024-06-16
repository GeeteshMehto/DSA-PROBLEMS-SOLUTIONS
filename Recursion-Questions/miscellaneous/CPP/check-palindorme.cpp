bool isPalindrome(string&s, int st, int e){
    if (st>e)
    {
        return true;
    }
    else if(s[st] != s[e]){
        return false;
    }
    else{
        return isPalindrome(s, ++st, --e);
    }
    
}
