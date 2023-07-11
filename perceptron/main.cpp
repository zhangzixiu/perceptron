#include <iostream>
#include <vector>

using namespace std;

class Perceptron {
private:
    vector<double> w;   // 权重向量
    double b;           // 偏置
    double lr;          // 学习率

public:
    Perceptron(int n, double learning_rate) {    // n为特征数
        lr = learning_rate;
        b = 0.0;
        w.resize(n, 0.0);
    }

    void train(vector<vector<double>> data) 
    {
        bool has_wrong = true;
        while (has_wrong) 
        {
            has_wrong = false;
            for (int i = 0; i < data.size(); ++i) 
            {
                double y = data[i].back();  // 获取标签
                double wx_plus_b = 0.0;
                for (int j = 0; j < w.size(); ++j) {
                    wx_plus_b += w[j] * data[i][j]; // 计算wx+b
                }
                wx_plus_b += b;

                if (y * wx_plus_b <= 0) {   // 判断是否误分类点
                    has_wrong = true;
                    for (int j = 0; j < w.size(); ++j) {
                        w[j] += lr * y * data[i][j];    // 更新权重
                    }
                    b += lr * y;    // 更新偏置
                }
            }
        }
    }

    int predict(vector<double> x) {
        double wx_plus_b = 0.0;
        for (int i = 0; i < w.size(); ++i) {
            wx_plus_b += w[i] * x[i];  // 计算wx+b
        }
        wx_plus_b += b;

        if (wx_plus_b > 0) {
            return 1;   // 返回正类
        } else {
            return -1;  // 返回负类
        }
    }
};

int main() {
    vector<vector<double>> data = {{3, 3, 1}, {4, 3, 1}, {1, 1, -1}, {2, 2, -1}}; // 训练数据

    Perceptron p(2, 0.1);   // 创建感知机对象，n=2（因为数据特征只有两个），学习率为0.1
    p.train(data);  // 训练感知机

    vector<vector<double>> test_data = {{0, 0}, {3, 3}, {4, 3}, {1, 1}, {2, 2},}; // 测试数据
    for (int i = 0; i < test_data.size(); ++i) {
        int label = p.predict(test_data[i]);
        cout << "(" << test_data[i][0] << ", " << test_data[i][1] << ") -> " << label << endl;
    }

    return 0;
}





/*
#include <iostream>
#include <vector>

using namespace std;

class Perceptron {
private:
    vector<double> w;   // 权重向量
    double b;           // 偏置
    double lr;          // 学习率

public:
    Perceptron(int n, double learning_rate) {    // n为特征数
        lr = learning_rate;
        b = 0.0;
        w.resize(n, 0.0);
    }

    void train(vector<vector<double>> data) 
    {
        bool has_wrong = true;
        while (has_wrong) 
        {
            has_wrong = false;
            for (int i = 0; i < data.size(); ++i) 
            {
                double y = data[i].back();  // 获取标签
                double wx_plus_b = 0.0;
                for (int j = 0; j < w.size(); ++j) {
                    wx_plus_b += w[j] * data[i][j]; // 计算wx+b
                }
                wx_plus_b += b;

                if (y * wx_plus_b <= 0) {   // 判断是否误分类点
                    has_wrong = true;
                    for (int j = 0; j < w.size(); ++j) {
                        w[j] += lr * y * data[i][j];    // 更新权重
                    }
                    b += lr * y;    // 更新偏置
                }
            }
        }
    }

    int predict(vector<double> x) {
        double wx_plus_b = 0.0;
        for (int i = 0; i < w.size(); ++i) {
            wx_plus_b += w[i] * x[i];  // 计算wx+b
        }
        wx_plus_b += b;

        if (wx_plus_b > 0) {
            return 1;   // 返回正类
        } else {
            return -1;  // 返回负类
        }
    }
};

int main() {
    vector<vector<double>> data = {{3, 3, 1}, {4, 3, 1}, {1, 1, -1}, {2, 2, -1}}; // 训练数据

    Perceptron p(2, 0.1);   // 创建感知机对象，n=2（因为数据特征只有两个），学习率为0.1
    p.train(data);  // 训练感知机

    vector<vector<double>> test_data = {{0, 0}, {3, 3}, {4, 3}, {1, 1}, {2, 2}}; // 测试数据
    for (int i = 0; i < test_data.size(); ++i) {
        int label = p.predict(test_data[i]);
        cout << "(" << test_data[i][0] << ", " << test_data[i][1] << ") -> " << label << endl;
    }

    return 0;
}
*/