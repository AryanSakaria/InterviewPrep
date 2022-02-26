class Solution:
    """
    https://leetcode.com/problems/3sum
    """
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n, p, z = [],[],[]
        answer = set()
        
        for num in nums:
            if num == 0:
                z.append(num)
            if num < 0:
                n.append(num)
            if num > 0:
                p.append(num)
                
        if len(z) > 2:
            answer.add((0,0,0))
            
        n_set = set(n)
        p_set = set(p)
        if len(z) >= 1:
            for i in n_set:
                if -i in p_set:
                    answer.add((i, 0, -i))
                    
        for i in range(len(n)-1):
            for j in range(i+1,len(n)):
                target = n[i] + n[j]
                if -target in p_set:
                    answer.add(tuple(sorted([n[i],n[j],-target])))
                    
        for i in range(len(p)-1):
            for j in range(i+1,len(p)):
                target = p[i] + p[j]
                if -target in n_set:
                    answer.add(tuple(sorted([p[i],p[j],-target])))
        return answer