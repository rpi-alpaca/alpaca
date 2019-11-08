
'''
ex: A
ex: (A) & (B)
ex: ((A) & (B)) | (C)
ex: (~A) or ~A
'''
string = "((c) > (((A) & (B)) | (D))) & (D)"
# string = "(a) & (c) | (d)"
print("String:", string)

invalid = False
operation = {"&", "|", ">", "="} # symbols that need two symbols next to them
# symbols that only need one: ~
# symbols that need to be completed: ( )

def next(raw, current): # gets the next character (excluding spaces)
	while current < len(raw) - 1 and raw[current + 1] == " ":
		current += 1
	if current < len(raw) - 1:
		return(True, raw[current + 1])
	return(False, raw[current])

def prev(raw, current): # gets the next character (excluding spaces)
	while current >= 0 and raw[current - 1] == " ":
		current -= 1
	if current >= 0:
		return(True, raw[current - 1])
	return(False, raw[current])

def matching(string): #function that returns a dictionary of matching parentheses
	par = {}
	stackParen = [] # a stack of the indecies of parentheses
	for i in range(len(string)):
		if string[i] == "(":
			# adds a paren to the stack
			stackParen.append(i)
			par[i] = -1
		elif string[i] == ")":
			# do another thing
			if not stackParen:
				return (False, {})
			par[stackParen[len(stackParen) - 1]] = i
			del stackParen[len(stackParen) - 1]
	for i in par: # checks if all the parens have a matching paren
		if par[i] == -1: # if is dosen't then it return an empty dictionary
			return (False, {})
	return (True, par)

(matches, loc) = matching(string)
print(loc)
if not matches:
	print("Mismatching Parenthesis")
else:
	revLoc = {} # ")" location: "(" location
	for item in loc:
		revLoc[loc[item]] = item
	prev = "" #keeps track of the previous item

	index = 0
	first = True
	# assume that the inputs will have spaces next to them
	for i in range(len(string)):
		if string[i] == " ": # spaces
			if first:
				invalid = True
				break
			continue

		if string[i] == "(": # left paren.
			if prev == "sy" or prev == ")":
				invalid = True
				break
			prev = string[i]

		elif string[i] == ")": # right paren.
			if prev == "(" or prev == "op" or prev == "~" or first:
				invalid = True
				break
			prev = string[i]

		elif string[i] in operation: # operations
			if prev == ")":
				# Only good input is if there is a ) before an operation
				prev = "op"
				if i-2 >= 0 and string[revLoc[i-2]]:
					break
			else:
				invalid = True
				break
		elif string[i] == "~": # negate operation
			if prev == "op" or prev == ")":
				invalid = True
				break
			prev = string[i]
			# make sure the next symbol

		else:
			if prev == ")" or prev == "op": # symbols
				invalid = True
				break
			if first: # edge case for the first item
				if next(string, 0)[0] == False: # checks if it is the only character
					invalid = True
					break
			prev = "sy"
			# symbol must be a letter then
			# will deal with additional symbols later
		index += 1
		first = False

	if invalid:
		print("Invalid string")
	else:
		print("Valid string")
