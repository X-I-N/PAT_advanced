#include <iostream>
#include <string>

using namespace std;

struct grade {
    string id;
    int score[4] = {0,};
    int rank[4] = {0,};
} stu[2000];
int n, m;

void get_rank(struct grade *student) {
    for (int i = 0; i < 4; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (stu[j].score[i] > student->score[i]) cnt++;
        }
        student->rank[i] = cnt;
    }
}

int get_stu_by_id(const string sid) {
    for (int i = 0; i < n; i++) if (stu[i].id == sid) return i;
    return -1;
}

void print_result(const struct grade student) {
    char subject[4] = {'A', 'C', 'M', 'E'};
    int min_value = student.rank[0];
    int min_idx = 0;
    for (int i = 1; i < 4; i++) {
        if (student.rank[i] < min_value) {
            min_value = student.rank[i];
            min_idx = i;
        }
    }
    cout << min_value << " " << subject[min_idx] << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id;
        cin >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
    }

    for (int i = 0; i < m; i++) {
        string sid;
        cin >> sid;
        int idx = get_stu_by_id(sid);
        if (idx != -1) {
            get_rank(&stu[idx]);
            print_result(stu[idx]);
        } else {
            cout << "N/A" << endl;
        }
    }
}

