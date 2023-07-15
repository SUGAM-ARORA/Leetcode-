class Solution:
    def dp(self,i,events,k,timeBooked,dct):
        if i<0 or k==0:
            return 0
        x=0
        if (i,k,timeBooked) in dct:
            return dct[(i,k,timeBooked)]
        if events[i][1]<timeBooked:
            x=self.dp(i-1,events,k-1,events[i][0],dct)+events[i][2]
        y=self.dp(i-1,events,k,timeBooked,dct)
        dct[(i,k,timeBooked)]=max(x,y)
        return max(x,y)
        
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n=len(events)
        dct={}
        events.sort(key=lambda x:x[1])
        return self.dp(n-1,events,k,float("infinity"),dct)
        