class TaskManager {
public:
    map<int, int> taskratingmap;
    map<int, int> taskusermap;
    priority_queue<pair<int, int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            taskratingmap[tasks[i][1]] = tasks[i][2];
            taskusermap[tasks[i][1]] = tasks[i][0];
            pq.push({tasks[i][2], tasks[i][1]});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskratingmap[taskId] = priority;
        taskusermap[taskId] = userId;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskratingmap[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskratingmap[taskId] = -1;
        taskusermap[taskId] = -1;
        pq.push({-1, taskId});
    }

    int execTop() {
        pair<int, int> highRated = pq.top();
        while (taskratingmap[highRated.second] != highRated.first) {
            pq.pop();
            highRated = pq.top();
        }
        int ans = taskusermap[highRated.second];
        rmv(highRated.second);
        return ans;
    }
};