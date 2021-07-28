class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not len(intervals):
            return [newInterval]
        i = 0
        left = []
        s, e = newInterval[0], newInterval[1]
        right = []
        
        while(i < len(intervals)):
            if intervals[i][1] < newInterval[0]:
                #Append it to left list
                left.append(intervals[i])
                
            if intervals[i][0] > newInterval[1]:
                #Append it to right list
                right.append(intervals[i])
            i += 1
            
                
        if left + right != intervals:
            s = min(s, intervals[len(left)][0])
            e = max(e, intervals[~len(right)][1])
                
            
        return left + [[s,e]] + right