def ReadData(fileName):

    # Read the file, splitting by lines
    f = open(fileName, 'r');
    lines = f.read().splitlines();
    f.close();

    items = [];

    for i in range(1, len(lines)):
        line = lines[i].split(',');
        itemFeatures = [];

        for j in range(len(line)-1):
            v = float(line[j]); # Convert feature value to float
            itemFeatures.append(v); # Add feature value to dict

        items.append(itemFeatures);

    shuffle(items);

    return items;


edit
play_arrow

brightness_4
def EuclideanDistance(x, y):
    S = 0; #  The sum of the squared differences of the elements
    for i in range(len(x)):
        S += math.pow(x[i]-y[i], 2);

    return math.sqrt(S); #The square root of the sum 
