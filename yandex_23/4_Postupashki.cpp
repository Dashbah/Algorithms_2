//
// Created by Dashbah on 09.04.2023.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num_countries, num_classmates;
    std::cin >> num_countries;

    std::vector<int> required_salary(num_countries + 1), requires_higher_edu(num_countries + 1), allows_children(num_countries + 1);

    for (int i = 1; i <= num_countries; ++i) {
        std::cin >> required_salary[i];
    }
    for (int i = 1; i <= num_countries; ++i) {
        std::cin >> requires_higher_edu[i];
    }
    for (int i = 1; i <= num_countries; ++i) {
        std::cin >> allows_children[i];
    }

    std::cin >> num_classmates;
    std::vector<int> classmates_salary(num_classmates + 1), has_higher_edu(num_classmates + 1), parents_citizenship(num_classmates + 1);

    for (int i = 1; i <= num_classmates; ++i) {
        std::cin >> classmates_salary[i];
    }
    for (int i = 1; i <= num_classmates; ++i) {
        std::cin >> has_higher_edu[i];
    }
    for (int i = 1; i <= num_classmates; ++i) {
        std::cin >> parents_citizenship[i];
    }


    std::vector<std::pair<int, int>> with_higher_edu;
    std::vector<std::pair<int, int>> without_higher_edu;
    for (int i = 1; i <= num_countries; i++) {
        if (requires_higher_edu[i]) {
            with_higher_edu.emplace_back(required_salary[i], i);
        } else {
            without_higher_edu.emplace_back(required_salary[i], i);
        }
    }

    sort(with_higher_edu.begin(), with_higher_edu.end());
    sort(without_higher_edu.begin(), without_higher_edu.end());
    std::vector<int> preferred_with_higher_edu;
    std::vector<int> preferred_without_higher_edu;

    for (int i = 0; i < with_higher_edu.size(); i++) {
        preferred_with_higher_edu.push_back(with_higher_edu[i].second);
        if (i > 0) {
            preferred_with_higher_edu[i] = std::min(preferred_with_higher_edu[i], preferred_with_higher_edu[i - 1]);
        }
    }
    for (int i = 0; i < without_higher_edu.size(); i++) {
        preferred_without_higher_edu.push_back(without_higher_edu[i].second);
        if (i > 0) {
            preferred_without_higher_edu[i] = std::min(preferred_without_higher_edu[i], preferred_without_higher_edu[i - 1]);
        }
    }

    for (int it = 1; it <= num_classmates; it++) {
        int salary = classmates_salary[it], has_higher_edu_req = has_higher_edu[it], parents_citizenship_req = parents_citizenship[it];

        int ans = num_countries + 1;
        if (parents_citizenship_req > 0 && allows_children[parents_citizenship_req] == 1) {
            ans = parents_citizenship_req;
        }

        int pos_with_higher_edu = upper_bound(with_higher_edu.begin(), with_higher_edu.end(), std::make_pair(salary + 1, 0)) -
                                  with_higher_edu.begin();
        int pos_without_higher_edu =
                upper_bound(without_higher_edu.begin(), without_higher_edu.end(), std::make_pair(salary + 1, 0)) -
                without_higher_edu.begin();
        --pos_with_higher_edu;
        --pos_without_higher_edu;

        if (pos_without_higher_edu >= 0) {
            ans = std::min(ans, preferred_without_higher_edu[pos_without_higher_edu]);
        }
        if (has_higher_edu_req && pos_with_higher_edu >= 0) {
            ans = std::min(ans, preferred_with_higher_edu[pos_with_higher_edu]);
        }
        if (ans == num_countries + 1) {
            ans = 0;
        }

        std::cout << ans << " ";
    }
}