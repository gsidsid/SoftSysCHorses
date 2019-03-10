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
