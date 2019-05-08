struct Person
{
    unsigned int walking_speed;
};

YAML::Node config = YAML::LoadFile("bridge.yaml");
std::vector<Person> get_people(unsigned int N)
{
    std::vector<Person> person(N);
    person = person.sort();
    person[i].walking_speed = speed;
    return person;
}
    
unsigned int get_minimum_crossing_time(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    auto person = get_people(n);
    
    if (n < 3)
    {
        return person.back().walking_speed;
    }
    else if (n == 3)
    {
        
        
        // Person 0 and 1 cross from A to B
        // Person 0 crosses back to A
        // Person 0 and 2 cross from A to B
        return person[1].walking_speed + person[0].walking_speed + person[2].walking_speed;
    }
    
    unsigned int time_taken = 0;
    
    // Person 0 and Person 1 cross from A to B
    time_taken += person[1].walking_speed;
    
    // Person 1 crosses back to A
    time_taken += person[1].walking_speed;
    
    // Person (n-2) and Person (n-1) cross from A to B
    time_taken += person[n-1].walking_speed;
    
    // Person 0 goes back and forth to escort everyone else
    for (unsigned int i = 1; i < n-2; ++i)
    {
        // Person 0 crosses back to A
        time_taken += person[0].walking_speed;
        
        // Person 0 and Person i cross from A to B
        time_taken += person[i].walking_speed;
    }
    
    return time_taken;
}
