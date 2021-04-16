int r, c;

void put1(vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (vec[i][j] == 0)
            {
                vec[i][j] = k;
                return;
            }
        }
    }
}

void put2(vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 2; j++)
        {
            if (vec[i][j] == 0 && vec[i][j + 1] == 0 && vec[i][j + 2] == 0)
            {
                vec[i][j] = k;
                vec[i][j + 1] = k;
                vec[i][j + 2] = k;
                return;
            }
        }
    }
}
void put3(vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            if (vec[i][j] == 0 && vec[i][j + 1] == 0 && vec[i + 1][j] == 0 && vec[i + 1][j + 1] == 0)
            {
                vec[i][j] = k;
                vec[i + 1][j] = k;
                vec[i][j + 1] = k;
                vec[i + 1][j + 1] = k;
                return;
            }
        }
    }
}

void put4(vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < r - 2; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            if (vec[i][j] == 0 && vec[i + 1][j + 1] == 0 && vec[i + 1][j] == 0 && vec[i + 2][j] == 0)
            {
                vec[i][j] = k;
                vec[i + 1][j] = k;
                vec[i + 2][j] = k;
                vec[i + 1][j + 1] = k;
                return;
            }
        }
    }
}

void put5(vector<vector<int>> &vec, int k)
{
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c - 2; j++)
        {
            if (vec[i + 1][j + 2] == 0 && vec[i][j + 1] == 0 && vec[i + 1][j] == 0 && vec[i + 1][j + 1] == 0)
            {
                vec[i + 1][j + 2] = k;
                vec[i + 1][j] = k;
                vec[i][j + 1] = k;
                vec[i + 1][j + 1] = k;
                return;
            }
        }
    }
}
vector<vector<int>> almostTetris(int n, int m, vector<int> f)
{
    vector<vector<int>> vec(n, vector<int>(m, 0));

    r = n, c = m;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == 1)
        {
            put1(vec, i + 1);
        }
        else if (f[i] == 2)
        {
            put2(vec, i + 1);
        }
        else if (f[i] == 3)
        {
            put3(vec, i + 1);
        }
        else if (f[i] == 4)
        {
            put4(vec, i + 1);
        }
        else if (f[i] == 5)
        {
            put5(vec, i + 1);
        }
    }
    return vec;
}
