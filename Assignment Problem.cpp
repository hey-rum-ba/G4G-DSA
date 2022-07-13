// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int cost[31][31]; 
    int n, max_match; 
    int lx[31], ly[31]; 
    int xy[31];
    int yx[31]; 
    bool S[31], T[31]; 
    int slack[31]; 
    int slackx[31]; 
    int prev_ious[31]; 
 
   void init_labels()
   {
       memset(lx, 0, sizeof(lx));
       memset(ly, 0, sizeof(ly));
       for (int x = 0; x < n; x++)
       for (int y = 0; y < n; y++)
       lx[x] = max(lx[x], cost[x][y]);
   }
   
    
   void update_labels()
   {
       int x, y;
       int delta = 99999999; 
       for (y = 0; y < n; y++) 
           if (!T[y])
               delta = min(delta, slack[y]);
       for (x = 0; x < n; x++) 
           if (S[x])
               lx[x] -= delta;
       for (y = 0; y < n; y++) 
           if (T[y])
               ly[y] += delta;
       for (y = 0; y < n; y++) 
           if (!T[y])
               slack[y] -= delta;
   }
   
   
   void add_to_tree(int x, int prev_iousx) 
   
   {
       S[x] = true; 
       prev_ious[x] = prev_iousx; 
       for (int y = 0; y < n; y++) 
           if (lx[x] + ly[y] - cost[x][y] < slack[y])
           {
               slack[y] = lx[x] + ly[y] - cost[x][y];
               slackx[y] = x;
           }
   }
   
   
   
   void augment() 
   {
       if (max_match == n) return; 
       int x, y, root; 
       int q[31], wr = 0, rd = 0; 

       memset(S, false, sizeof(S)); 
       memset(T, false, sizeof(T)); 
       memset(prev_ious, -1, sizeof(prev_ious)); 
       
       for (x = 0; x < n; x++) 
       {
           if (xy[x] == -1)
           {
               q[wr++] = root = x;
               prev_ious[x] = -2;
               S[x] = true;
               break;
           }
       }
       
       for (y = 0; y < n; y++) 
       {
           slack[y] = lx[root] + ly[y] - cost[root][y];
           slackx[y] = root;
       }
       
       
       while (true) 
       {
           while (rd < wr) 
           {
               x = q[rd++]; 
               for (y = 0; y < n; y++) 
                   if (cost[x][y] == lx[x] + ly[y] && !T[y])
                   {
                       if (yx[y] == -1) break; 
                           T[y] = true; 
                       q[wr++] = yx[y];
                       add_to_tree(yx[y], x); 
                   }
               if (y < n)
                   break;
           }
           if (y < n)
               break; 
           
           update_labels();
           
           wr = rd = 0; 
           for (y = 0; y < n; y++) 
           
           if (!T[y] && slack[y] == 0)
           {
               if (yx[y] == -1) 
               {
                   x = slackx[y];
                   break;
               }
               else
               {
                   T[y] = true; 
                   if (!S[yx[y]]) 
                   {
                       q[wr++] = yx[y]; 
                       add_to_tree(yx[y], slackx[y]); 
                   }
               }
           }
           if (y < n) break; 
       }
       
       if (y < n) 
       {
           max_match++;
           for (int cx = x, cy = y, ty; cx != -2; cx = prev_ious[cx], cy = ty)
           {
               ty = xy[cx];
               yx[cy] = cx;
               xy[cx] = cy;
           }
           augment(); 
       }
   }
    
   int hungarian()
   {
       int ret = 0; 
       max_match = 0;
       memset(xy, -1, sizeof(xy)); 
       memset(yx, -1, sizeof(yx));
       init_labels(); 
       augment(); 
       
       for (int x = 0; x < n; x++)
           ret += cost[x][xy[x]];
   
       return ret;
   }
   
   int assignmentProblem(int Arr[], int N) {
       
       n = N;
       for(int i=0; i<n; i++)
           for(int j=0; j<n; j++)
               cost[i][j] = -1*Arr[i*n+j];
               
       int ans = -1 * hungarian();
       
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        
        int Arr[n*n];
        for(int i=0; i<n*n; i++)
            cin>>Arr[i];

        Solution ob;
        cout << ob.assignmentProblem(Arr,n) << endl;
    }
    return 0;
}  // } Driver Code Ends