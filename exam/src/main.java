import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class CustomObject {
    private String name;
    private int intValue;
    private double doubleValue;

    public CustomObject(String name, int intValue, double doubleValue) {
        this.name = name;
        this.intValue = intValue;
        this.doubleValue = doubleValue;
    }

    public String getName() {
        return name;
    }

    public int getIntValue() {
        return intValue;
    }

    public double getDoubleValue() {
        return doubleValue;
    }
}

 class ComparatorExample {
    public static void main(String[] args) {
        // Sorting strings
        List<String> strings = new ArrayList<>();
        strings.add("Orange");
        strings.add("Apple");
        strings.add("Banana");

        Comparator<String> stringComparator = new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return s1.compareTo(s2);
            }
        };
        Collections.sort(strings, stringComparator);

        System.out.println("Sorted Strings:");
        for (String str : strings) {
            System.out.println(str);
        }

        // Sorting custom objects
        List<CustomObject> objects = new ArrayList<>();
        objects.add(new CustomObject("Object 1", 30, 1.5));
        objects.add(new CustomObject("Object 1", 10, 1.7));
        objects.add(new CustomObject("Object 2", 20, 2.7));

        Comparator<CustomObject> customComparator = new Comparator<CustomObject>() {
            @Override
            public int compare(CustomObject o1, CustomObject o2) {
                int nameComparison = o1.getName().compareTo(o2.getName());
                if (nameComparison != 0) {
                    return nameComparison;
                }
                int intValueComparison = Integer.compare(o1.getIntValue(), o2.getIntValue());
                if (intValueComparison != 0) {
                    return intValueComparison;
                }
                return Double.compare(o1.getDoubleValue(), o2.getDoubleValue());
            }
        };
        Collections.sort(objects, customComparator);

        System.out.println("\nSorted Custom Objects:");
        for (CustomObject obj : objects) {
            System.out.println("Name: " + obj.getName() + ", IntValue: " + obj.getIntValue() + ", DoubleValue: " + obj.getDoubleValue());
        }
    }
}
