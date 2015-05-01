Json::Value root;   // will contain the root value after parsing.
Json::Reader reader;
std::ifstream stream("E:\\Sample\\JSON PARSER\\Debug\\test.json", std::ifstream::binary);
bool parsingSuccessful = reader.parse( stream, root, false );
std::string encoding = root["type"].asString();
std::cout << encoding << "\n";
