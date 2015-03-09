shoppinglist = []										# empty list

item = input("Enter an item or type -1 to exit ")


while item != -1:
	shoppinglist.append(item)							# put the item in the array
	item = input("Enter an item or type -1 to exit ")	# reprompt the user


print ("The customer needs to purchase ")
print (len(shoppinglist))
print ("items, these items are")
print (shoppinglist)