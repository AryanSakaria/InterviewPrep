class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        #if single element
        if len(intervals) == 1:
            return intervals
        
        #sort by first value
        intervals.sort()
        #track current interval
        print(intervals)
        s,e = intervals[0]
        ans = [intervals[0]]
        for i in range(len(intervals[1:])):
            if intervals[i+1][0] > e:
                s,e = intervals[i+1]
                ans.append([s,e])
            else:
                e = max(e, intervals[i+1][1])
                ans[-1][1] = e
        return ans
        