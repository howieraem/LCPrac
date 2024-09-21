import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    uniq_salaries = employee['salary'].drop_duplicates()

    if len(uniq_salaries) < 2:
        return pd.DataFrame({'SecondHighestSalary': [None]})

    second_highest = uniq_salaries.nlargest(2).iloc[-1]
    return pd.DataFrame({'SecondHighestSalary': [second_highest]})
