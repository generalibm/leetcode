#ifndef SRC_ZHANGHONG_SRC_00146_LRU_CACHE_00146_LRU_CACHE_H_
#define SRC_ZHANGHONG_SRC_00146_LRU_CACHE_00146_LRU_CACHE_H_

#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class LRUCache {
public:
    static const int THRESH = INT_MAX / 2;

    LRUCache(int capacity)
    : m_capacity(capacity)
    , m_data()
    {

    }

    int get(int key)
    {
        auto idx = m_data.find(key);
        if (m_data.end() == idx)
        {
            return -1;
        }

        idx->second.setFrequence(THRESH);

        decreaseOther(key);
        idx->second.setModifed(true);

        printAll();

        return idx->second.getValue();
    }

    void put(int key, int value)
    {

        auto idx = m_data.find(key);
        if (idx != m_data.end())
        {
            m_data[key] = Record(key, value, THRESH, true);

            decreaseOther(key);
            return;
        }

        int deleted_key = key;

        if (m_capacity == m_data.size())
        {
            int freq = INT_MAX;

            for (auto & e : m_data)
            {
                if (e.second.getFrequence() < freq  && !e.second.isModifed())
                {
                    freq = e.second.getFrequence();
                    deleted_key = e.first;
                }
            }

            if (1 == m_data.size())
            {
                deleted_key = m_data.begin()->first;
            }

            m_data.erase(deleted_key);
        }

        m_data[key] = Record(key, value, THRESH, true);

        decreaseOther(key);

        printAll();
    }
private:
    void decreaseOther(int key)
    {
        for (auto & e : m_data)
        {
            if (key != e.first)
            {
                e.second.setFrequence(e.second.getFrequence()-1);
                e.second.setModifed(false);
            }
        }
    }

    void printAll()
    {
        for (auto e : m_data)
        {
            std::cout << "{" << e.first << ", " << e.second.toString() << "}" << std::endl;
        }
        std::cout << "---" << std::endl;
    }

private:
    class Record {
    public:
        Record()
        {
            m_key = -1;
            m_value = -1;
            m_frequence = THRESH;
            m_modified = true;
        }

        explicit Record(int key, int value, int frequence, bool modified)
        {
            m_key = key;
            m_value = value;
            m_frequence = frequence;
            m_modified = modified;
        }

//        Record(Record && record)
//        {
//            m_key = record.getKey();
//            m_value = record.getValue();
//            m_frequence = record.getFrequence();
//            m_modified = record.isModifed();
//        }

        int getFrequence() const
        {
            return m_frequence;
        }

        void setFrequence(int frequence)
        {
            m_frequence = frequence;
        }

        int getKey() const
        {
            return m_key;
        }

        void setKey(int key)
        {
            m_key = key;
        }

        int getValue() const
        {
            return m_value;
        }

        void setValue(int value)
        {
            m_value = value;
        }


        bool isModifed() const
        {
            return m_modified;
        }

        void setModifed(bool modifed)
        {
            m_modified = modifed;
        }

        string toString()
        {
            return "<" + type_cast<int, string>(getKey()) + "," + type_cast<int, string>(getValue()) + ","
                    + type_cast<int, string>(getFrequence()) + "," + type_cast<bool, string>(isModifed()) + ">";
        }

        template<typename T1, typename T2>
        T2 type_cast(T1 t1)
        {
            T2  t2;
            stringstream ss;
            ss << t1;
            ss >> t2;

            return t2;
        }


    private:
        int m_key;
        int m_value;
        int m_frequence;
        bool m_modified;
    };
private:
    size_t m_capacity;
    unordered_map<int, Record> m_data;
};

#endif /* SRC_ZHANGHONG_SRC_00146_LRU_CACHE_00146_LRU_CACHE_H_ */
