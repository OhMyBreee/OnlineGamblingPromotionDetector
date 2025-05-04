#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Structure to hold data from processed_comments.csv
struct ProcessedComment {
    string video_id;
    string video_title;
    string comment;
    string label;
};

// Structure to hold data from first_400_data_online_gambling_ads_labelled.csv
struct AnnotatedComment {
    string annotation_id;
    string annotator;
    string comment;
    string created_at;
    string id;
    string lead_time;
    string sentiment;
    string updated_at;
    string video_id;
    string video_title;
};

// Function to split a string by delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

// Function to trim whitespace and remove unwanted apostrophes, quotes, and special characters
string cleanLabel(const string& label) {
    string cleanedLabel = label;
    
    // Remove leading and trailing spaces
    cleanedLabel.erase(remove_if(cleanedLabel.begin(), cleanedLabel.end(), ::isspace), cleanedLabel.end());
    
    // Remove any quotes around the string
    if (cleanedLabel.front() == '"' && cleanedLabel.back() == '"') {
        cleanedLabel = cleanedLabel.substr(1, cleanedLabel.size() - 2); // Remove the quotes
    }

    // Handle specific case where "No Online Gambling Promotion" should be treated as "Not Online Gambling Promotion"
    if (cleanedLabel == "NoOnlineGamblingPromotion") {
        cleanedLabel = "NotOnlineGamblingPromotion";
    }

    // Remove special characters like emojis or other non-ASCII characters
    cleanedLabel.erase(remove_if(cleanedLabel.begin(), cleanedLabel.end(), [](unsigned char c) {
        return !(std::isalnum(c) || std::isspace(c));  // Keep only alphanumeric characters and spaces
    }), cleanedLabel.end());

    // Normalize case (convert to lowercase for case-insensitive comparison)
    transform(cleanedLabel.begin(), cleanedLabel.end(), cleanedLabel.begin(), ::tolower);
    
    return cleanedLabel;
}

// Function to read processed_comments.csv
vector<ProcessedComment> readProcessedComments(const string& filename) {
    vector<ProcessedComment> comments;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return comments;
    }
    
    string line;
    getline(file, line); // Skip the header
    
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields.size() == 4) {
            comments.push_back({fields[0], fields[1], fields[2], cleanLabel(fields[3])});
        }
    }
    
    file.close();
    return comments;
}

// Function to read first_400_data_online_gambling_ads_labelled.csv
vector<AnnotatedComment> readAnnotatedComments(const string& filename) {
    vector<AnnotatedComment> comments;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return comments;
    }
    
    string line;
    getline(file, line); // Skip the header
    
    while (getline(file, line)) {
        vector<string> fields = split(line, ',');
        if (fields.size() == 10) { // Ensure that there are 10 fields
            comments.push_back({fields[0], fields[1], fields[2], fields[3], fields[4],
                                fields[5], cleanLabel(fields[6]), fields[7], fields[8], fields[9]});
        }
    }
    
    file.close();
    return comments;
}

// Function to compare label and sentiment for the first 400 comments
int compareLabelsAndSentiments(const vector<ProcessedComment>& processedComments, 
                               const vector<AnnotatedComment>& annotatedComments) {
    int matchCount = 0;
    
    // Compare only the first 400 comments
    for (int i = 0; i < 400 && i < processedComments.size() && i < annotatedComments.size(); ++i) {
        if (processedComments[i].label == annotatedComments[i].sentiment) {
            matchCount++;
        }
    }
    
    return matchCount;
}

int main() {
    string processedFile = "processed_comments.csv";
    string annotatedFile = "first_400_data_online_gambling_ads_labelled.csv";
    
    // Read the data from the CSV files
    vector<ProcessedComment> processedComments = readProcessedComments(processedFile);
    vector<AnnotatedComment> annotatedComments = readAnnotatedComments(annotatedFile);
    
    // Ensure both files have sufficient data
    if (processedComments.size() < 400 || annotatedComments.size() < 400) {
        cerr << "One of the files does not have 400 comments." << endl;
        return 1;
    }

    // Compare label and sentiment
    int matches = compareLabelsAndSentiments(processedComments, annotatedComments);
    cout << "Total matches between 'label' and 'sentiment' for the first 400 comments: " << matches << endl;
    
    return 0;
}

