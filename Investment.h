#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <string>

using namespace std;

class Investment {
    private:
        double m_investment;
        double m_monthlyDeposit;
        int m_annualInterest;
        int m_numYears;
    public:
        void SetInvestment(double t_investment);
        void SetMonthlyDeposit(double t_monthlyDeposit);
        void SetAnnualInterest(int t_annualInterest);
        void SetNumYears(int t_numYears);
        double GetInvestment();
        double GetMonthlyDeposit();
        int GetAnnualInterest();
        int GetNumYears();
        Investment();
        Investment(double t_investment, double t_MonthlyDeposit, int t_numYears, int t_annualInterest);
};


#endif