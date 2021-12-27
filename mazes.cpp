/* Eric Ly
 * Overgrown Mazes
 * HSPT 2016 Online Edition
 */

#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>

using namespace std;

// Make a direction array
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int oo = -1;
int r, c;

int main()
{
   int T; cin >> T;
   for(int cc = 1; cc <= T; cc++)
   {
      cin >> r >> c;
      string g[r];
      for(int i = 0; i < r; i++) cin >> g[i];
      int sx = 0;
      int sy = 0;
      int ex = 0;
      int ey = 0;
      int d[r][c];
      for(int i = 0; i < r; i++)
      {
         for(int j = 0; j < c; j++)
         {
            // Initialize array with infinities indicating we have not went to this location
            d[i][j] = oo;

            // If we find the start or end, save these locations
            if(g[i][j] == 'S')
            {
               sx = i;
               sy = j;
            }
            if(g[i][j] == 'E')
            {
               ex = i;
               ey = j;
            }
         }
      }

      // Make a Deque so we can add to either the front or back
      deque<int> q;
      q.push_back(sx);
      q.push_back(sy);

      // Initialize the start with a zero
      d[sx][sy] = 0;

      // We will perform a 0/1 BFS
      // Basically if we take an edge that adds a cost to our current answer to push to the back of the que
      // If we take an edge that has no cost then we can push it to the front of the que
      while(q.size() > 0)
      {
         int x = q.front(); q.pop_front();
         int y = q.front(); q.pop_front();
         for(int i = 0; i < 4; i++)
         {
            int nx = x+dx[i];
            int ny = y+dy[i];
            // Check bounds
            if(0 <= nx && nx < r && 0 <= ny && ny < c && d[nx][ny] == oo)
            {
               // We hit a bush, so add 1 to our answer
               if(g[nx][ny] == '#')
               {
                  d[nx][ny] = d[x][y]+1;
                  q.push_back(nx);
                  q.push_back(ny);
               }
               // This is a free edge so we can evaluate it right away
               else
               {
                  d[nx][ny] = d[x][y];
                  q.push_front(ny);
                  q.push_front(nx);
               }
            }
         }
      }

      // Print answer
      printf("Maze #%d: %d\n", cc, d[ex][ey]);
   }
   return 0;
}
