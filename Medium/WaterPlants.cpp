int wateringPlants(vector<int>& plants, int capacity) {
        int result = 0, cap = capacity;
        for(int i = 0; i<plants.size(); i++)
        {
            result++;
            if(cap >= plants[i])
            {
                cap -= plants[i];
            }
            else
            {
                result += 2*(i);
                cap = capacity - plants[i];
            }
        }
        return result;
    }
