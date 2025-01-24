import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    columns_names =['student_id','age']
    df =pd.DataFrame(student_data,columns=columns_names)
    return df