#User function Template for python3

class Solution:
    """
    https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
    """
    def cutRod(self, price, n):
        #code here
        DP = [0 for _ in range(n+1)]
        for i in range(1, n+1):
            for j in range(1,i+1):
                DP[i] = max(DP[i], price[j-1] + DP[i-j])
        return DP[-1]
        
#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.cutRod(a, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends