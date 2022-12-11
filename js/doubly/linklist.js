class Node {
	constructor(previous = null, data, next = null) {
		this.previous = previous;
		this.data = data;
		this.next = next;
	}
}

class Linklist {


	constructor(head = null) {
		this.head = head
		this.size = 0;
	}

	// insert Node in Starting 
	insertFirst(data) {
		
		let back = this.head;
		this.head = new Node(this.previous, data, this.head);
		if(this.size > 0)
			back.previous = this.head;
		this.size++;

	}

	// Insert Last
	insertLast(data) {

		let current = this.head;
		while(current.next){
			current = current.next;
		}
		
		let newNode = new Node(current,data,null)
		current.next = newNode;
		console.log(current);
		

	}

	//  Insert On Index
	insertAt(data, index) {
		// out of range

	}

	// Print list
	get() {

		let current = this.head;
		let data = [];
		while(current){
			data.push(current);
			current = current.next;
		}
		return data;
	}

	// Get On Index
	getAt(index) {

	}

	// Remove At
	removeAt(index) {

	}

	// Clear list
	clearList() {
		this.head = null;
		this.size = 0;
	}
}



// let list = new Linklist();
// list.insertFirst(12)
// list.insertFirst(13)
// list.insertFirst(14)
// list.insertFirst(15)
// list.insertFirst(16)
// console.log(list)