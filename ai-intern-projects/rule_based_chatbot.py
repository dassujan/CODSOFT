import re       # pip install regex
import time     # pip install TIME-python
import random   # pip install random2
import string   # pip install string

# Function to generate chatbot responses
def chatbot_response(user_input):
    # Convert user input to lower case for easier matching
    user_input = user_input.lower()
    
    # Greeting responses
    # Check if the user input contains any of the greeting keywords 'hello', 'hi', or 'hey'
    if re.search(r'\bhello\b|\bhi\b|\bhey\b', user_input):
        return "Hello! How can I assist you today?"

    # Asking for time
    # Check if the user input contains keywords related to asking for the current time
    elif re.search(r'\btime\b|\bcurrent time\b|\bwhat time is it\b', user_input):
        # Return the current time in the format Hour:Minute AM/PM
        return f"The current time is {time.strftime('%I:%M %p')}."

    # Asking for date
    # Check if the user input contains keywords related to asking for the current date
    elif re.search(r'\bdate\b|\bcurrent date\b|\bwhat date is it\b', user_input):
        # Return today's date in the format Month Day, Year (e.g., August 20, 2024)
        return f"Today's date is {time.strftime('%B %d, %Y')}."

    # Asking for chatbot's name or identity
    # Check if the user input contains phrases asking for the chatbot's name or identity
    elif re.search(r'\byour name\b|\bwho are you\b', user_input):
        return "I'm a simple rule-based chatbot created to assist you with basic queries."

    # Farewell responses
    # Check if the user input contains keywords related to ending the conversation
    elif re.search(r'\bbye\b|\bexit\b|\bquit\b', user_input):
        return "Goodbye! Have a great day!"

    # Default response for unknown inputs
    # If the user input doesn't match any of the above patterns, provide a default response
    else:
        return "I'm sorry, I didn't understand that. Can you please rephrase?"

# Main loop for chatbot interaction
def chat():
    print("Chatbot: Hello! I am a rule-based chatbot. Type 'exit' to end the conversation.")
    while True:
        # Take input from the user
        user_input = input("You: ")
        # Generate a response based on the user's input
        response = chatbot_response(user_input)
        # Print the chatbot's response
        print(f"Chatbot: {response}")
        # Check if the user wants to exit the chat
        if re.search(r'\bexit\b|\bbye\b|\bquit\b', user_input.lower()):
            break

# Run the chatbot
chat()