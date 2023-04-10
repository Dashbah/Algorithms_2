#include <iostream>
#include <vector>

struct Country {
    int id;
    int reqSalary;
    bool isHigherEducationReq;
    bool areChildrenAllowed;
};

struct Classmate {
    int salary;
    bool isHigherEducation;
    int parentsCitizenship;
};

bool required(const Classmate &classmate, const Country &country) {
    return (classmate.parentsCitizenship == country.id && country.areChildrenAllowed) || ((classmate.salary >= country.reqSalary) &&
            (!country.isHigherEducationReq || (country.isHigherEducationReq && classmate.isHigherEducation)));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Country> countries(n);

    for (int i = 0; i < n; ++i) {
        countries[i].id = i + 1;
        std::cin >> countries[i].reqSalary;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> countries[i].isHigherEducationReq;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> countries[i].areChildrenAllowed;
    }

    int q;
    std::cin >> q;
    std::vector<Classmate> classmates(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> classmates[i].salary;
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> classmates[i].isHigherEducation;
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> classmates[i].parentsCitizenship;
    }

    for (auto &classmate: classmates) {
        bool lucky = false;
        for (auto &country: countries) {
            if (required(classmate, country)) {
                lucky = true;
                std::cout << country.id << " ";
                break;
            }
        }
        if (!lucky) {
            // don't print " " at the end
            std::cout << 0 << " ";
        }
    }

    return 0;
}