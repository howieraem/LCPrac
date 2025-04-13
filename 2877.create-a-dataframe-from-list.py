import pandas as pd

COLS = ['student_id', 'age']

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=COLS)
