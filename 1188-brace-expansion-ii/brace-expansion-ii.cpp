class Solution {
public:
    int idx,n;
    string s;
    set<string>getUnit(){
        set<string>res;
        if(s[idx]=='{'){
            idx++;
            res=performUnion();
        }
        else{
            res.insert(string(1,s[idx]));
        }
        idx++;
        return res;
    }
    set<string>performConcatenation(){
        set<string>result={""};
        while(idx<n && ((s[idx]=='{')||isalpha(s[idx]))){
            set<string>temp=getUnit();
            set<string>currResult;
            for(auto &it1:result){
                for(auto &it2:temp){
                    currResult.insert(it1+it2);
                }
            }
            result=currResult;
        }
        return result;
    }
    set<string>performUnion(){
        set<string>result;
        while(idx<n){
            set<string>temp=performConcatenation();
            result.insert(temp.begin(),temp.end());
            if(idx<n && s[idx]==',') idx++;
            else break;
        }
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        this->idx=0;
        this->n=expression.size();
        this->s=expression;
        set<string>st=performUnion();
        return vector<string>(st.begin(),st.end());
    }
};