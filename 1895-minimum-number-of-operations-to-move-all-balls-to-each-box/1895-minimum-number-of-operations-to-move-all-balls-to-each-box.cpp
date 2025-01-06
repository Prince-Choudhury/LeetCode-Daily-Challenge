class Solution {
public:
    vector<int> minOperations(string boxes) {
	    int len=boxes.size(), runCnt=0,posSum=0,count=0,totalPosSum=0;
	    vector<int> minOps(len);
	    for(int i=0; i<len; i++)
		    if(boxes[i]=='1'){
			    count++;
			    totalPosSum+=i;
		    }
	    for(int i=0; i<len; i++){
		    if(boxes[i]=='1'){
			    runCnt++;
			    posSum+=i;
		    }

		    minOps[i]=i*((runCnt<<1)-count)+totalPosSum-(posSum<<1);
	    }
	    return minOps;
    }
};