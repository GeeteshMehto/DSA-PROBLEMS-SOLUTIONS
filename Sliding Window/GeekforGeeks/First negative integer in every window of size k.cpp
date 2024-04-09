/*
Question Link:- https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        vector<long long> ans;
        deque<long long int> dq;
        
        //process first window of k size
        
        for(int i=0; i<K; i++){
            if(A[i]<0){
                dq.push_back(i);
            }
        }
        
        //store ans of first k size window
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        // process for remianing windows
        for(int i=K; i<N; i++){
            //removal
            if(!dq.empty() && i - dq.front() >=K){
                dq.pop_front();
            }
            
            //addition
            if(A[i]<0){
                dq.push_back(i);
            }
            
            //store ans
            if(dq.size()>0){
            ans.push_back(A[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
                                       
 }