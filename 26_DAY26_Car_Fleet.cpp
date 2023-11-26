class Solution {

    class Car{
        public:
            int pos;
            int speed;
            
            Car(int pos, int speed){
                this->pos = pos;
                this->speed = speed;
            }
    };

    //Custom Comparator
    static bool myComp(Car&a, Car&b){
        return a.pos<b.pos;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i = 0; i<position.size(); i++){
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), myComp);

        stack<float>st;
        for(auto car:cars){
            float time = (target - car.pos)/((float) car.speed);
            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};