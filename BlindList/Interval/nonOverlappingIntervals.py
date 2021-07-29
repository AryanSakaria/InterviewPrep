class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x : x[1])
        s,e = intervals[0][1], intervals[0][1]
        count = 0
        """
        Greedy solution
        Heuristic: Choose min x where x is end time
        min end time means we can fit in more intervals
        from intervals[x:]
        If we took y > x
        It is impossible to fit more intervals in intervals[y:] 
        than in intervals[x:]
        """
        for i in range(1, len(intervals)):
            if e <= intervals[i][0]:
                e = intervals[i][1]
            else:
                count += 1
                
        return count