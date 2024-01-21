# GridMap2dに使う障害物の座標を生成するスクリプト
input_data = [
    "0000000000",
    "0100000000",
    "0111111111",
    "0101000000",
    "0001011110",
    "0101000010",
    "0001111010",
    "0000000010",
    "1111111110",
    "0000000000",
]

def find_coordinates(data):
    coordinates = []
    rows = len(data)
    for y in range(rows):
        for x, char in enumerate(data[y]):
            if char == '1':
                coordinates.append({'x': x, 'y': rows - y - 1})
    return coordinates

def print_coordinates(coordinates):
    for coord in coordinates:
        print(f"\t{{{coord['x']}, {coord['y']}}},")

print("std::vector<Eigen::Vector2i> obstalces =")
print("{")
print_coordinates(find_coordinates(input_data))
print("};")