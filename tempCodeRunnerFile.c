while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; i < 7; i++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
