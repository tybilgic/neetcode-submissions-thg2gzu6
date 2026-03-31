class Solution {
public:
    bool isValid(string s) {
        stack<char> charstack;
        for (const auto& c : s)
        {
            bool push = false;
            char expected;
            switch(c)
            {
                case '(':
                case '[':
                case '{':
                    push = true;
                    break;
                case ')':
                    expected = '(';
                    break;
                case ']':
                    expected = '[';
                    break;
                case '}':
                    expected = '{';
                    break;
            }

            if (push)
            {
                charstack.push(c);
            }
            else
            {
                if (charstack.empty() || charstack.top() != expected)
                    return false;
                charstack.pop();
            }
        }

        return charstack.empty();
    }
};
