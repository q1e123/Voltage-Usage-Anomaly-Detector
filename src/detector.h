

struct Model{
    double max;
    double min;
};

struct Point{
    double voltage;
};

bool predict(Model model, Point point){
    if(model.max >= point.voltage && model.min <= point.voltage){
        return true;
    }
    else{
        return false;
    }
}

Model train(Point train_data[], size_t train_data_size){
    Point * p_end_of_struct = &(train_data[train_data_size-1]);
    Model model;
    model.max = 0;
    model.min = 10000;
    for(Point * ptr = train_data; ptr != p_end_of_struct; ptr+=1){
        if(ptr -> voltage <= model.min){
            model.min = ptr -> voltage;
        }
        if(ptr -> voltage >= model.max){
            model.max = ptr -> voltage;
        }
    }
    return model;


}

Model load(char* file_path){

}

void save(Model model, char* file_path){

}