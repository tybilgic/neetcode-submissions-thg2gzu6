class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereqs(numCourses);
        for (auto& p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];
            prereqs[course].push_back(prereq);
        }

        vector<int> visited(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                if (dfs(i, prereqs, visited))
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool dfs(int course, vector<vector<int>>& prereqs, vector<int>& visited)
    {
        if (visited[course] == 1)
        {
            return true;
        }

        if (visited[course] == 2)
        {
            return false;
        }

        visited[course] = 1;

        for (int i = 0; i < prereqs[course].size(); i++)
        {
            if (dfs(prereqs[course][i], prereqs, visited))
            {
                return true;
            }
        }

        visited[course] = 2;

        return false;
    }
};
